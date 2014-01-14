
void crawlerAI(Object *enemy)
{
    
    /*
      Hokay, so here's zeh wurld. 
      
      The idea behind the crawler A.I. is that it moves clock-wise around a 
      block (4-sided all flat). When it reaches the end of the block's 
      line segment (that particular side), it switches to the next segment
      and rotates accordingly. The continues for all sides.
      
      Process:
              1) Check current orientation 
              2) Check line segment of orientation 
              3) If line segment is at its end
                 a) snap to next segment
                 b) rotate accordingly (Not sure if Nate wants this just yet?)
              4) Move according to orientation
              
      */
        
        /*
          So how can we check if it's the end of the block? Well, if there are no more 
          collisions for that orientation, the segment must be over.
        */
        
        int left, right, top, bottom;
        
           switch(enemy->facing)
           {
        case FACING_LEFT:
             
             // There's something coming up to the left. See if there's an escape route 
             if(collided_tl((enemy->x - enemy->xspeed)  - COLLISION_BUFFER, enemy->y - COLLISION_BUFFER))
             {
                  // Can we go up?
                  if(!collided_tl((enemy->x)  - COLLISION_BUFFER, (enemy->y - enemy->yspeed) - COLLISION_BUFFER))
                  {
                       enemy->facing = FACING_UP;
                       enemy->lastContact = d_left;
                  } // or down?
                  else if(!collided_tl((enemy->x)  - COLLISION_BUFFER, (enemy->y + enemy->yspeed) + COLLISION_BUFFER))
                  {
                       enemy->facing = FACING_DOWN;
                       enemy->lastContact = d_left;
                  }
             }
             else // Nothing? Keep going.
                  lastx = x;
                 x -= vx;
            break;
        case RIGHT:
             
             // There's something coming up to the right. See if there's an escape route 
             if(collided_tl((x + vx)  + COLLISION_BUFFER, y - COLLISION_BUFFER))
             {
                  // Can we go up?
                  if(!collided_tl((x)  - COLLISION_BUFFER, (y - vy) - COLLISION_BUFFER))
                  {
                       facing = UP;
                       lastContact = RIGHT;
                  } // or down?
                  else if(!collided_tl((x)  - COLLISION_BUFFER, (y + vy) + COLLISION_BUFFER))
                  {
                       facing = DOWN;
                       lastContact = RIGHT;
                  }
             }
             else // Nothing? Keep going.
                 lastx = x;
                 x += vx;
            break;
        case UP:
             
             // There's something coming up above. See if there's an escape route 
             if(collided_tl(x - COLLISION_BUFFER, (y - vy) - COLLISION_BUFFER))
             {
                  // Can we go left?
                  if(!collided_tl((x - vx)  - COLLISION_BUFFER, (y) - COLLISION_BUFFER))
                  {
                       facing = LEFT;
                       lastContact = UP;
                  } // or right?
                  else if(!collided_tl((x + vx)  - COLLISION_BUFFER, (y) - COLLISION_BUFFER))
                  {
                       facing = RIGHT;
                       lastContact = UP;
                  }
             }
             else // Nothing? Keep going.
                 lasty = y;
                 y -= vy;
            break;
        case DOWN:
             // There's something coming below. See if there's an escape route 
             if(collided_tl(x - COLLISION_BUFFER, (y + vy) + COLLISION_BUFFER))
             {
                  // Can we go left?
                  if(!collided_tl((x - vx) - COLLISION_BUFFER, (y) + COLLISION_BUFFER))
                  {
                       facing = LEFT;
                       lastContact = DOWN;
                  } // or right?
                  else if(!collided_tl((x + vx) - COLLISION_BUFFER, (y) + COLLISION_BUFFER))
                  {
                       facing = RIGHT;
                       lastContact = DOWN;
                  }
             }
             else // Nothing? Keep going.
                 lasty = y;
                 y += vy;
            break;
        default:

     break;
     }
                                /*Find segment based on current collision*/
        
        // Collision on block's right
         left = collided_tl(enemy->x - enemy->xspeed, enemy->y - 0);
        
        // Collision on block's left
         right = collided_tl(enemy->x + enemy->xspeed, enemy->y - 0);
        
        // Collision on block's top
        
         bottom = collided_tl(enemy->x - 0, enemy->y + enemy->yspeed);
        
        // Collision on block's bottom
         top = collided_tl(enemy->x + 0, enemy->y - enemy->yspeed);
        
     if(enemy->lastContact != d_none)
     {           
        if(enemy->lastContact == d_left && !left) // We went off the block
                       {
                              enemy->facing = FACING_LEFT;
                              
                              if(enemy->lasty > enemy->y)
                                   enemy->lastContact = d_down;
                              else if(enemy->lasty < enemy->y)
                                   enemy->lastContact = d_up;                       
                       }
        else if(enemy->lastContact == d_right && !right) // We went off the block
                       {
                                   enemy->facing = FACING_RIGHT; 
                                  
                              if(enemy->lasty > enemy->y)
                                   enemy->lastContact = d_down;
                              else if(enemy->lasty < enemy->y)
                                   enemy->lastContact = d_up;
                       }
       else  if(enemy->lastContact == d_up && !top) // We went off the block
                       {
                                   enemy->facing = FACING_UP; 
                                   
                              if(enemy->lastx > enemy->x)
                                   enemy->lastContact = d_right;
                              else if(enemy->lastx < enemy->x)
                                   enemy->lastContact = d_left;
                       }
        else if(enemy->lastContact == d_down && !bottom) // We went off the block
                       {
                                   enemy->facing = FACING_DOWN; 
                                   
                               if(enemy->lastx > enemy->x)
                                   enemy->lastContact = d_right;
                              else if(enemy->lastx < enemy->x)
                                   enemy->lastContact = d_left;
                       }   
     }     
     
}
     